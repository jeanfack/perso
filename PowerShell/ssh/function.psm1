
function isAdmin {
  return (New-Object Security.Principal.WindowsPrincipal ([Security.Principal.WindowsIdentity]::GetCurrent())).IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)
}

function isNotAdmin {
  return (-not (isAdmin))
}

function install {
  param([string]$name)

  if ((Get-WindowsCapability -Online -Name $name).State -ne 'Installed') {
      Add-WindowsCapability -Online -Name "$name"
  }    
}

function installSsh {
  install("OpenSSH.Client~~~~0.0.1.0")
  install("OpenSSH.Server~~~~0.0.1.0")
}

function uninstall {
  param([string]$name)

  if ((Get-WindowsCapability -Online -Name $name).State -ne 'Installed') {
      Remove-WindowsCapability -Name "$name"
  }    
}

function uninstallSsh {
  uninstall("OpenSSH.Client~~~~0.0.1.0")
  uninstall("OpenSSH.Server~~~~0.0.1.0")
}

function isInstalled {
  param([string]$name)

  if ((Get-WindowsCapability -Online -Name "$name").State -eq 'Installed') {
    Write-Output "$name is Installed"
  }
  else {
    Write-Output "$name is Uninstalled"
  }
}

function isInstalledSsh {
  isInstalled("OpenSSH.Client~~~~0.0.1.0")
  isInstalled("OpenSSH.Server~~~~0.0.1.0")
}

function setSshAutomatic {
  Set-Service "sshd" -StartupType "Automatic"
  Set-Service "ssh-agent" -StartupType "Automatic"
}

function setSshDisabled {
  Set-Service "sshd" -StartupType "Disabled"
  Set-Service "ssh-agent" -StartupType "Disabled"
}

function startSsh {
  Start-Service -Name "sshd"
  Start-Service -Name "ssh-agent"
}

function stopSsh {
  Stop-Service -Name "sshd"
  Stop-Service -Name "ssh-agent"
}
