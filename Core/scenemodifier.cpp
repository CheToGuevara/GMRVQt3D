/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "scenemodifier.h"


#include <Qt3DRender/QGeometryRenderer>





Qt3DCore::QEntity * SceneModifier::addBasicShape( TBasicShape type )
{
  Qt3DCore::QEntity * newEntity = new Qt3DCore::QEntity( );
  Qt3DRender::QGeometryRenderer * shape;
  switch ( type )
  {
    case Cube:
      // Cuboid shape data
      shape = new Qt3DExtras::QCuboidMesh( );

      break;
    case  Sphere:
      shape = new Qt3DExtras::QSphereMesh( );
      break;
    case  Plane:
      shape = new Qt3DExtras::QPlaneMesh( );
      break;
    case Torus:
      shape = new Qt3DExtras::QTorusMesh( );
      dynamic_cast<Qt3DExtras::QTorusMesh*>(shape)->setRadius( 1.0f );
      dynamic_cast<Qt3DExtras::QTorusMesh*>( shape )->setMinorRadius( 0.4f );
      dynamic_cast<Qt3DExtras::QTorusMesh*>( shape )->setRings( 100 );
      dynamic_cast<Qt3DExtras::QTorusMesh*>( shape )->setSlices( 20 );
      break;
    case  Cone:
      shape = new Qt3DExtras::QConeMesh( );
      break;
    case   Cylinder:
      shape = new Qt3DExtras::QCylinderMesh( );
      break;
    default:
      shape = new Qt3DExtras::QCuboidMesh( );
      break;
  }

  newEntity->addComponent( shape );
  // CuboidMesh Transform
  Qt3DCore::QTransform *newTransform = new Qt3DCore::QTransform( );

  //Cuboid Material
  Qt3DExtras::QPhongMaterial *newMaterial = new Qt3DExtras::QPhongMaterial( );
  newMaterial->setDiffuse( QColor( QRgb( 0x222222 ) ) );

  newEntity->addComponent( newTransform );
  newEntity->addComponent( newMaterial );

  return newEntity;
}

