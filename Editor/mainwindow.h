/**
* @file    MainWindow.h
* @brief
* @author  Author 1 <author1@domain.com>
* @author  Author 2 <author2@domain.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


//QT Includes
#include <QMainWindow>

//QT3D Includes
#include <Qt3DCore/qentity.h>


namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT



public:
  explicit MainWindow( QWidget *parent = 0 );
  ~MainWindow( );

  public slots:
  void on_actionCube_triggered( bool checked = false );
  void on_actionSphere_triggered( bool checked = false );
  void on_actionPlane_triggered( bool checked = false );
  void on_actionTorus_triggered( bool checked = false );
  void on_actionCone_triggered( bool checked = false );
  void on_actionCylinder_triggered( bool checked = false );


protected:

  Qt3DCore::QEntity *rootEntity;

private:

  Ui::MainWindow *ui;


  


};

#endif // MAINWINDOW_H
