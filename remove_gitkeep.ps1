# PowerShell script to remove .gitkeep files from all subfolders if the folder contains other files

# Get all .gitkeep files recursively
$gitkeepFiles = Get-ChildItem -Path . -Filter .gitkeep -Recurse

foreach ($file in $gitkeepFiles) {
    $folder = $file.Directory
    # Count files in the folder except .gitkeep
    $otherFiles = Get-ChildItem -Path $folder.FullName | Where-Object { $_.Name -ne ".gitkeep" }
    if ($otherFiles.Count -gt 0) {
        Remove-Item $file.FullName
        Write-Host "Removed: $($file.FullName)"
    }
}
