/*=========================================================================

  Module:    vtkKWComboBox.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkKWComboBox - a text entry widget with a pull-down menu of values
// .SECTION Description
// A simple subclass of entry that adds a pull-down menu where a predefined
// set of values can be chosed to set the entry field.
// .SECTION Thanks
// This work is part of the National Alliance for Medical Image
// Computing (NAMIC), funded by the National Institutes of Health
// through the NIH Roadmap for Medical Research, Grant U54 EB005149.
// Information on the National Centers for Biomedical Computing
// can be obtained from http://nihroadmap.nih.gov/bioinformatics.
// .SECTION See Also
// vtkKWEntry

#ifndef __vtkKWComboBox_h
#define __vtkKWComboBox_h

#include "vtkKWEntry.h"

class vtkKWApplication;

class KWWIDGETS_EXPORT vtkKWComboBox : public vtkKWEntry
{
public:
  static vtkKWComboBox* New();
  vtkTypeRevisionMacro(vtkKWComboBox,vtkKWEntry);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Create the widget.
  virtual void Create(vtkKWApplication *app);

  // Description:
  // Add and delete values to put in the list.
  virtual void AddValue(const char* value);
  virtual void DeleteValue(int idx);
  virtual int HasValue(const char* value);
  virtual int GetValueIndex(const char* value);
  virtual const char* GetValueFromIndex(int idx);
  virtual int GetNumberOfValues();
  virtual void DeleteAllValues();

  // Description:
  // Replace the nth value in the combo box with another string value.
  virtual void ReplaceNthValue( int n, const char* value );

  // Description:
  // Set/Get the value of the entry in a few different formats.
  // Overriden to comply with the Tk type
  virtual void SetValue(const char *);

  // Description:
  // Specifies a command to associate with the widget. This command is 
  // typically invoked when the return key is pressed, or the focus is lost,
  // or a value is picked from the dropdown list.
  // The first argument is the object that will have the method called on it.
  // The second argument is the name of the method to be called and any
  // arguments in string form. If the object is NULL, the method
  // is evaluated as a simple command.
  virtual void SetCommand(vtkObject *object, const char *method);

  // Description:
  // Update the "enable" state of the object and its internal parts.
  // Depending on different Ivars (this->Enabled, the application's 
  // Limited Edition Mode, etc.), the "enable" state of the object is updated
  // and propagated to its internal parts/subwidgets. This will, for example,
  // enable/disable parts of the widget UI, enable/disable the visibility
  // of 3D widgets, etc.
  virtual void UpdateEnableState();

protected:
  vtkKWComboBox() {};
  ~vtkKWComboBox() {};
  
private:
  vtkKWComboBox(const vtkKWComboBox&); // Not implemented
  void operator=(const vtkKWComboBox&); // Not Implemented
};


#endif



