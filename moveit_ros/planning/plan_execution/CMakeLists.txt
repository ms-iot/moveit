set(MOVEIT_LIB_NAME moveit_plan_execution)

add_library(${MOVEIT_LIB_NAME}
  src/plan_with_sensing.cpp
  src/plan_execution.cpp)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION ${${PROJECT_NAME}_VERSION})
target_link_libraries(${MOVEIT_LIB_NAME}
  moveit_planning_pipeline
  moveit_trajectory_execution_manager
  moveit_planning_scene_monitor
  ${catkin_LIBRARIES} ${Boost_LIBRARIES}
  )
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

install(TARGETS ${MOVEIT_LIB_NAME}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(DIRECTORY include/ DESTINATION include)
