<?php
include 'db.php';

$status = $_POST['status'];
$sql = "UPDATE led_status SET status_led='$status' WHERE id=1";

if ($conn->query($sql) === TRUE) {
  echo "OK";
} else {
  echo "Error: " . $conn->error;
}

$conn->close();
?>
