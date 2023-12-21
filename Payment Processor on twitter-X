<?php

// Check if the Dogecoin library is included
if (!class_exists('Dogecoin')) {
    require_once('path/to/dogecoin-library.php');
}

// Function to handle Dogecoin payments
function handle_dogecoin_payment($amount, $transaction_id) {
    // Connect to Dogecoin network
    $dogecoin = new Dogecoin();
    $dogecoin->connect();
    
    // Check if the transaction is valid
    if ($dogecoin->validate_transaction($transaction_id)) {
        // Update user balance
        update_user_balance($amount);
        
        // Return success
        return true;
    }
    
    // Return failure
    return false;
}

// Function to update user balance
function update_user_balance($amount) {
    // Fetch the user ID
    $user_id = get_current_user_id();
    
    // Update the user balance in the database
    $query = "UPDATE users SET balance = balance + {$amount} WHERE id = {$user_id}";
    $result = mysql_query($query);
    
    // Check for errors
    if (!$result) {
        // Log error
        error_log('Failed to update user balance: ' . mysql_error());
        
        // Return failure
        return false;
    }
    
    // Return success
    return true;
}

// Function to handle payment form submission
function handle_payment_form_submit() {
    // Check if the form was submitted
    if (!isset($_POST['submit'])) {
        return;
    }
    
    // Check if the payment method is Dogecoin
    if ($_POST['payment_method'] !== 'dogecoin') {
        return;
    }
    
    // Validate amount
    $amount = floatval($_POST['amount']);
    if ($amount <= 0) {
        // Log error
        error_log('Invalid amount: ' . $amount);
        
        // Return failure
        return false;
    }
    
    // Validate transaction ID
    $transaction_id = $_POST['transaction_id'];
    if (empty($transaction_id)) {
        // Log error
        error_log('Transaction ID is missing');
        
        // Return failure
        return false;
    }
    
    // Handle Dogecoin payment
    $result = handle_dogecoin_payment($amount, $transaction_id);
    
    // Check the result
    if ($result) {
        // Log success
        error_log('Dogecoin payment succeeded');
        
        // Redirect to success page
        header('Location: /payment_success.php');
        exit;
    } else {
        // Log error
        error_log('Dogecoin payment failed');
        
        // Redirect to failure page
        header('Location: /payment_failure.php');
        exit;
    }
}

// Add form handling hook
add_action('init', 'handle_payment_form_submit');

?>
