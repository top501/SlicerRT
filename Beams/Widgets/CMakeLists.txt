project(qSlicer${MODULE_NAME}ModuleWidgets)

set(KIT ${PROJECT_NAME})

set(${KIT}_EXPORT_DIRECTIVE "Q_SLICER_MODULE_${MODULE_NAME_UPPER}_WIDGETS_EXPORT")

set(${KIT}_INCLUDE_DIRECTORIES
  ${vtkSlicerBeamsModuleLogic_INCLUDE_DIRS}
  )

set(${KIT}_SRCS
  qMRMLBeamParametersTabWidget.cxx
  qMRMLBeamParametersTabWidget.h
  qMRMLBeamsTableView.cxx
  qMRMLBeamsTableView.h
  )

set(${KIT}_MOC_SRCS
  qMRMLBeamParametersTabWidget.h
  qMRMLBeamsTableView.h
)

set(${KIT}_UI_SRCS
  Resources/UI/qMRMLBeamParametersTabWidget.ui
  Resources/UI/qMRMLBeamsTableView.ui
  )

set(${KIT}_RESOURCES
  #Resources/${KIT}.qrc
  )

set(${KIT}_TARGET_LIBRARIES
  vtkSlicerBeamsModuleMRML
  vtkSlicerBeamsModuleLogic
  )

SET (${KIT}_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${vtkSlicerBeamsModuleLogic_INCLUDE_DIRS} CACHE INTERNAL "" FORCE)
  
#-----------------------------------------------------------------------------
SlicerMacroBuildModuleWidgets(
  NAME ${KIT}
  EXPORT_DIRECTIVE ${${KIT}_EXPORT_DIRECTIVE}
  INCLUDE_DIRECTORIES ${${KIT}_INCLUDE_DIRECTORIES}
  SRCS ${${KIT}_SRCS}
  MOC_SRCS ${${KIT}_MOC_SRCS}
  UI_SRCS ${${KIT}_UI_SRCS}
  TARGET_LIBRARIES ${${KIT}_TARGET_LIBRARIES}
  RESOURCES ${${KIT}_RESOURCES}
  WRAP_PYTHONQT
  )

#-----------------------------------------------------------------------------
if(BUILD_TESTING)
  #add_subdirectory(Testing)
endif()

#-----------------------------------------------------------------------------
add_subdirectory(DesignerPlugins)
