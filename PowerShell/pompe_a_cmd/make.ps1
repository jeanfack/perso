

Out-File -FilePath .\output.txt

foreach($line in Get-Content .\input.txt) {
  Write-Output "pipo$line" >> .\output.txt
}
