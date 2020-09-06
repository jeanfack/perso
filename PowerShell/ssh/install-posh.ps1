if (!(Get-Module -ListAvailable -Name "Posh-SSH")) {
    Install-Module -Force -Name "Posh-SSH"
}

Get-InstalledModule -Name "Posh-SSH"
