/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkDummyRenderer.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkDummyRenderer.h"
#include "vtkGraphicsFactory.h"
#include "vtkCommand.h"

#include <stdlib.h>
#include <string.h>

vtkCxxRevisionMacro(vtkDummyRenderer, "1.2");

// Create a vtkDummyRenderer with a black background, a white ambient light, 
// two-sided lighting turned on, a viewport of (0,0,1,1), and backface culling
// turned off.
vtkDummyRenderer::vtkDummyRenderer()
{
}

vtkDummyRenderer::~vtkDummyRenderer()
{
}

// return the correct type of Renderer 
vtkDummyRenderer *vtkDummyRenderer::New()
{ 
  return new vtkDummyRenderer;
}

// Concrete render method.
void vtkDummyRenderer::Render(void)
{
  vtkProp  *aProp;
  vtkActor *actor;
  vtkMapper *mapper;

  this->InvokeEvent(vtkCommand::StartEvent,NULL);

  this->Props->InitTraversal(); 
  while ( (aProp = this->Props->GetNextProp()) )
    {
    if ( aProp->GetVisibility() )
      {
      actor = vtkActor::SafeDownCast(aProp);
      if (actor)
        {
        mapper = actor->GetMapper();
        if (mapper)
          {
          mapper->Update();
          }
        }
      }
    }
  this->InvokeEvent(vtkCommand::EndEvent,NULL);
}

void vtkDummyRenderer::RenderOverlay()
{
}

void vtkDummyRenderer::DeviceRender()
{
}

void vtkDummyRenderer::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}

float vtkDummyRenderer::GetPickedZ()
{
  return 0.0;
}

void vtkDummyRenderer::DevicePickRender()
{
}

void vtkDummyRenderer::StartPick(unsigned int pickFromSize)
{
}

void vtkDummyRenderer::UpdatePickId()
{
}

void vtkDummyRenderer::DonePick()
{
}

unsigned int vtkDummyRenderer::GetPickedId()
{
  return 0;
}



