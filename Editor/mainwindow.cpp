#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <scenemodifier.h>

#include <QGuiApplication>

#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcameralens.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtGui/QScreen>

#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DExtras/qforwardrenderer.h>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

MainWindow::MainWindow( QWidget *parent ) :
QMainWindow( parent ),
ui( new Ui::MainWindow )
{
  ui->setupUi( this );


  Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow( );
  view->defaultFrameGraph( )->setClearColor( QColor( QRgb( 0x4d4d4f ) ) );
  QWidget *container = QWidget::createWindowContainer( view );
  QSize screenSize = view->screen( )->size( );
  container->setMinimumSize( QSize( 200, 100 ) );
  container->setMaximumSize( screenSize );


  ui->MainLayout->addWidget( container, 1, 1 );


  Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
  view->registerAspect( input );

  // Root entity
  rootEntity = new Qt3DCore::QEntity( );

  // Camera
  Qt3DRender::QCamera *cameraEntity = view->camera( );

  cameraEntity->lens( )->setPerspectiveProjection( 45.0f, 16.0f / 9.0f, 0.1f, 1000.0f );
  cameraEntity->setPosition( QVector3D( 0, 0, 20.0f ) );
  cameraEntity->setUpVector( QVector3D( 0, 1, 0 ) );
  cameraEntity->setViewCenter( QVector3D( 0, 0, 0 ) );

  Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity( rootEntity );
  Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight( lightEntity );
  light->setColor( "white" );
  light->setIntensity( 1 );
  lightEntity->addComponent( light );
  Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform( lightEntity );
  lightTransform->setTranslation( cameraEntity->position( ) );
  lightEntity->addComponent( lightTransform );

  // For camera controls
  Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController( rootEntity );
  camController->setCamera( cameraEntity );

  // Scenemodifier
  //SceneModifier *modifier = new SceneModifier( rootEntity );

  // Set root object of the scene
  view->setRootEntity( rootEntity );



}


void MainWindow::on_actionCube_triggered( bool checked )
{
  Qt3DCore::QEntity * shape;

  shape = SceneModifier::addBasicShape( SceneModifier::Cube );
  shape->setParent( rootEntity );

}

void MainWindow::on_actionSphere_triggered( bool checked  )
{
  Qt3DCore::QEntity * shape;

  shape = SceneModifier::addBasicShape( SceneModifier::Sphere );
  shape->setParent( rootEntity );
}
void MainWindow::on_actionPlane_triggered( bool checked  )
{
  Qt3DCore::QEntity * shape;

  shape = SceneModifier::addBasicShape( SceneModifier::Plane );
  shape->setParent( rootEntity );
}
void MainWindow::on_actionTorus_triggered( bool checked )
{
  Qt3DCore::QEntity * shape;

  shape = SceneModifier::addBasicShape( SceneModifier::Torus );
  shape->setParent( rootEntity );
}
void MainWindow::on_actionCone_triggered( bool checked  )
{
  Qt3DCore::QEntity * shape;

  shape = SceneModifier::addBasicShape( SceneModifier::Cone );
  shape->setParent( rootEntity );
}
void MainWindow::on_actionCylinder_triggered( bool checked  )
{
  Qt3DCore::QEntity * shape;

  shape = SceneModifier::addBasicShape( SceneModifier::Cylinder );
  shape->setParent( rootEntity );
}

MainWindow::~MainWindow( )
{

  delete ui;
}

