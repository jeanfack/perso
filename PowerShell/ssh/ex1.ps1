# Affiche "Hello World"
Write-Output "Hello World"

# Affiche le nom du PC
Write-Output $env:computername

#$env:computername
#Write-Output "$env:ProgramData\ssh\sshd_config"

function isAdmin {

    #$User = [Security.Principal.WindowsIdentity]::GetCurrent()
    #$Role = (New-Object Security.Principal.WindowsPrincipal $user).IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)

    #return (New-Object Security.Principal.WindowsPrincipal $User).IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)
    return (New-Object Security.Principal.WindowsPrincipal ([Security.Principal.WindowsIdentity]::GetCurrent())).IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)
}

if (-not (isAdmin)) {
    throw "Le compte ne dispose pas des droits admin."
}

#Get-WindowsCapability -Online | ? Name -like 'OpenSSH*'

#$a = (Get-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0)

#Write-Output ( $a.State -eq "Installed")

#Write-Output ((Get-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0).State -eq 'Installed')

#Write-Output ((Get-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0)::State -eq 'Installed')
#Write-Output (Get-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0)::State


# $name="OpenSSH.Client~~~~0.0.1.0"
# $name="OpenSSH.Server~~~~0.0.1.0"

function install {
    param([string]$name)

    if ((Get-WindowsCapability -Online -Name "OpenSSH.Client~~~~0.0.1.0").State -ne 'Installed') {
        Add-WindowsCapability -Online -Name "OpenSSH.Client~~~~0.0.1.0 is Installed"
    }    
}

#if ((Get-WindowsCapability -Online -Name "OpenSSH.Client~~~~0.0.1.0").State -ne 'Installed') {
#    Add-WindowsCapability -Online -Name "OpenSSH.Client~~~~0.0.1.0 is Installed"
#}
#
#if ((Get-WindowsCapability -Online -Name "OpenSSH.Client~~~~0.0.1.0").State -eq 'Installed') {
#    Write-Output "OpenSSH.Client~~~~0.0.1.0 is Installed"
#}
#else {
#    Write-Output "OpenSSH.Client~~~~0.0.1.0 is Uninstalled"
#}

