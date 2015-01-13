/***************************************************************************
                           abstractspicekernel.h
                             ----------------
    begin                : Sat Jan 10 2014
    copyright            : (C) 2014 by Vadim Kuznetsov
    email                : ra3xdh@gmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/



#ifndef ABSTRACTSPICEKERNEL_H
#define ABSTRACTSPICEKERNEL_H

#include <QtCore>
#include "schematic.h"

class AbstractSpiceKernel : public QObject
{
    Q_OBJECT
private:
    QString netlist,workdir;
    QString simulator_cmd;
    QString simulator_parameters;
    QProcess *SimProcess;

    QStringList sims,vars,output_files;

    QString output;

protected:
    Schematic *Sch;

    virtual void createNetlist(QTextStream& stream, int NumPorts,QStringList& simulations,
                               QStringList& vars, QStringList &outputs);

public:

    enum Simulator {Ngspice, Xyce, NoSimulator};

    explicit AbstractSpiceKernel(Schematic *sch_, Simulator kern,
                                 QObject *parent = 0);
    ~AbstractSpiceKernel();

    void parseNgSpiceSimOutput(QString ngspice_file,
                          QList< QList<double> > &sim_points,
                          QStringList &var_list, bool &isComplex);
    void convertToQucsData(const QString &qucs_dataset);
    QString getOutput();

    
signals:
    void started();
    void finished();
    void errors(QProcess::ProcessError);
    
public slots:
    void slotSimulate();
    void killThemAll();
    void slotErrors(QProcess::ProcessError err);
    void slotFinished();
    
};

#endif // ABSTRACTSPICEKERNEL_H