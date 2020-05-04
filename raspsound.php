  
?php
$row = $_POST['row'];
$max = $_POST['max'];
$peaks = $_POST['peaks'];
$col = $_POST['col'];
$today = date("Y-m-d H:i:s");
$record = $today . ", " . $row . " " . $col . " " . $peaks . " " . $max . "\n";
$file = "sound.log";
if(file_exists($file))
        $fp = fopen($file, "a");
else
        $fp = fopen($file, "w");

fwrite($fp, $record);
fclose($fp);
echo "From e1900317\n";

?>
