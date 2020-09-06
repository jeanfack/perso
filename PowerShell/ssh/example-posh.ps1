$user="user"
$pass="Kooper00"
$secpass=ConvertTo-SecureString $pass -AsPlainText -Force
#$cred = new-object -typename System.Management.Automation.PSCredential -argumentlist $user,$pass
$cred=new-object System.Management.Automation.PSCredential($user,$secpass)

$sessionid=New-SSHSession -ComputerName $(hostname) -Credential $cred

# command cmd.exe
$command="dir"
#$command="echo %CD%"
$res=Invoke-SSHCommand -Index $sessionid.sessionid -Command $command

$res.output
