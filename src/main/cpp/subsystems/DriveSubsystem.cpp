#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
    : m_leftscgroup(m_leftLeader, m_leftFollower)
    , m_rightscgroup(m_rightLeader, m_rightFollower)
    , m_drive(m_leftscgroup,m_rightscgroup)
    , m_odometry(frc::Rotation2d())
    , m_gyro()
{
    m_rightscgroup.SetInverted(true);
}


void DriveSubsystem::Drive(double xSpeed, double zRotation, bool squareInputs /*= true*/)
{
    m_drive.ArcadeDrive(xSpeed, zRotation, squareInputs);
}

void DriveSubsystem::Periodic() {
    m_odometry.Update(m_gyro.GetHeadingAsRot2d()
                    , units::inch_t(m_leftLeader.GetSelectedSensorPosition(0) / m_ticksPerInch)
                    , units::inch_t(m_rightLeader.GetSelectedSensorPosition(0) / m_ticksPerInch));
}

frc::Pose2d DriveSubsystem::GetPose() {
    return m_odometry.GetPose();
}

void DriveSubsystem::SetWheelSpeeds(units::meters_per_second_t leftSpeed, units::meters_per_second_t rightSpeed) {
    m_drive.TankDrive(leftSpeed.to<double>(), rightSpeed.to<double>());
}