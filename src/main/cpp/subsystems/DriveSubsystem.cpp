#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
    :m_leftscgroup(m_LeftLeader, m_LeftFollower)
    ,m_rightscgroup(m_RightLeader, m_RightFollower)
    ,m_drive(m_leftscgroup,m_rightscgroup)
{
    m_rightscgroup.SetInverted(true);   


}


void DriveSubsystem::Drive(double xSpeed,
    double zRotation,
    bool squareInputs /*= true*/)
{
    m_drive.ArcadeDrive(xSpeed,
     zRotation,
     squareInputs);
}