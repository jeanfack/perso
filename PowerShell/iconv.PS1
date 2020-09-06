$strString = "Hello World"
write-host $strString

# $encodingASCII = [System.Text.Encoding]::ASCII

write-Output "CodePage Name DisplayName" | Out-File out.txt

Foreach($ei in [System.Text.Encoding]::GetEncodings()) 
{ 
   write-Output "$($ei.CodePage) $($ei.Name) $($ei.DisplayName)" | Out-File out.txt -append
   # bloc d'instructions / traitement
}
