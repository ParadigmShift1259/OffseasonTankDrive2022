#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>

using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

class DriveSubsystem : public frc2::SubsystemBase

{
public:
    DriveSubsystem();
    void Drive(double xSpeed,
    double zRotation,
    bool squareInputs = true);


private:
    frc::DifferentialDrive m_drive;
    WPI_TalonFX m_LeftLeader{5};
    WPI_TalonFX m_LeftFollower{6};
    WPI_TalonFX m_RightLeader{3};
    WPI_TalonFX m_RightFollower{2};
    frc::SpeedControllerGroup m_leftscgroup;
    frc::SpeedControllerGroup m_rightscgroup;



};