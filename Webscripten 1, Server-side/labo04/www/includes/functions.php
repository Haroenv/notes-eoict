<?php

    // @TODO: Insert showDbError Here
  function showDbError($msg,$userMessage) {
    if (DEBUG) {
      var_dump($msg);
      exit();
    } else {
      file_put_contents(
          __DIR__ . '/error_log_mysql',
          PHP_EOL . (new DateTime())->format('Y-m-d H:i:s') . ' : ' . $msg,
          FILE_APPEND
      );
      header('location: error.php?msg=' . $userMessage);
      exit();
    }
  }
// EOF