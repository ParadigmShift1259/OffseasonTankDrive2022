// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/RamseteCommand.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc2/command/InstantCommand.h>
#include <vector>

#include "commands/ExampleCommand.h"
#include "subsystems/DriveSubsystem.h"
#include <frc/XBOXController.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  frc2::SequentialCommandGroup* GetCommandGroup();
  frc2::RamseteCommand GetCommandPath();

 private:
  // The robot's subsystems and commands are defined here...
  DriveSubsystem m_drive;
  ExampleSubsystem m_Subsystem;
  frc2::Command* m_autonomousCommand = nullptr;
  frc::Trajectory m_trajectory;
  frc::RamseteController m_ramseteController;

  frc::XboxController m_primaryController{0};

  void ConfigureButtonBindings();
};
