<?php
include 'db.php';

$result = $conn->query("SELECT status_led FROM led_status WHERE id=1");
$row = $result->fetch_assoc();
echo $row["status_led"];

$conn->close();
?>