/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

// Qt includes
#include <QtPlugin>

// Slicer includes
#include <qSlicerCoreApplication.h>
#include <qSlicerModuleManager.h>

// DoseAccumulation Logic includes
#include <vtkSlicerDoseAccumulationModuleLogic.h>

// DoseAccumulation includes
#include "qSlicerDoseAccumulationModule.h"
#include "qSlicerDoseAccumulationModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerDoseAccumulationModule, qSlicerDoseAccumulationModule);

//-----------------------------------------------------------------------------
/// \ingroup SlicerRt_QtModules_DoseAccumulation
class qSlicerDoseAccumulationModulePrivate
{
public:
  qSlicerDoseAccumulationModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerDoseAccumulationModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerDoseAccumulationModulePrivate::qSlicerDoseAccumulationModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerDoseAccumulationModule methods

//-----------------------------------------------------------------------------
qSlicerDoseAccumulationModule::qSlicerDoseAccumulationModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerDoseAccumulationModulePrivate)
{
}

//-----------------------------------------------------------------------------
QStringList qSlicerDoseAccumulationModule::categories()const
{
  return QStringList() << "Radiotherapy";
}

//-----------------------------------------------------------------------------
qSlicerDoseAccumulationModule::~qSlicerDoseAccumulationModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerDoseAccumulationModule::helpText()const
{
  QString help = 
    "This module accumulates the multiple dose distribution maps into one dose map. "
    "For more information see <a href=\"%1/Documentation/%2.%3/Modules/DoseAccumulation\">%1/Documentation/%2.%3/Modules/DoseAccumulation</a><br>";
  return help.arg(this->slicerWikiUrl()).arg(Slicer_VERSION_MAJOR).arg(Slicer_VERSION_MINOR);
}

//-----------------------------------------------------------------------------
QString qSlicerDoseAccumulationModule::acknowledgementText()const
{
  return "This work is part of SparKit project, funded by Cancer Care Ontario (CCO)'s ACRU program and Ontario Consortium for Adaptive Interventions in Radiation Oncology (OCAIRO).";
}

//-----------------------------------------------------------------------------
QStringList qSlicerDoseAccumulationModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Csaba Pinter (Queen's)");
  moduleContributors << QString("Andras Lasso (Queen's)");
  moduleContributors << QString("Kevin Wang (UHN, Toronto)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerDoseAccumulationModule::icon()const
{
  return this->Superclass::icon();
  //return QIcon(":/Icons/DoseAccumulation.png");
}

//-----------------------------------------------------------------------------
void qSlicerDoseAccumulationModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerDoseAccumulationModule::createWidgetRepresentation()
{
  return new qSlicerDoseAccumulationModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerDoseAccumulationModule::createLogic()
{
  return vtkSlicerDoseAccumulationModuleLogic::New();
}
