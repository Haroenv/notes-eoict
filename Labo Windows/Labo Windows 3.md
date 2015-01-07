##Labo 3: Powershell

### Basisopdrachten

1. Get-ChildItem -File | sort length -Descending
2. Get-ChildItem | ForEach-Object{Write-Host $_.mode}
3. Get-Command Set-* | Write-Host
4. Get-Command Set-* | ForEach{ if( $_.CommandType -eq "Cmdlet") {Write-Host $_.name} }

### Korte scripts

1.
Clear-Host
Get-Process | Select-Object Company | Group-Object Company | Sort-Object Count

2.
Param([string] $bron $doel)
robocopy  $bron $doel /B
ls $doel