#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <units/length.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>

#include "Gyro.h"

using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

class DriveSubsystem : public frc2::SubsystemBase

{
public:
    DriveSubsystem();
    void Drive(double xSpeed, double zRotation, bool squareInputs = true);
    void Periodic();
    frc::Pose2d GetPose();
    void SetWheelSpeeds(units::meters_per_second_t leftSpeed, units::meters_per_second_t rightSpeed);
    frc::DifferentialDriveKinematics kDriveKinematics{m_trackWidth};

private:
    frc::DifferentialDrive m_drive;
    WPI_TalonFX m_leftLeader{5};
    WPI_TalonFX m_leftFollower{6};
    WPI_TalonFX m_rightLeader{3};
    WPI_TalonFX m_rightFollower{2};
    frc::SpeedControllerGroup m_leftscgroup;
    frc::SpeedControllerGroup m_rightscgroup;
    frc::DifferentialDriveOdometry m_odometry;
    Gyro m_gyro;
    double m_ticksPerInch = 286.479; //5400 ticks per rev divided by 6 pi (circumfrence of 6.0_in diameter wheels)
    units::inch_t m_trackWidth = 24.5_in; //track width from middle of wheels
};