#include "mainwindow.h"

#include <QApplication>


int main( int argc, char* argv[] )
{
  QApplication app( argc, argv );

  MainWindow Qt3DEditor;

  Qt3DEditor.show( );

  return app.exec( );
}