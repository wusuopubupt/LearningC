//@Reference : http://geeksquiz.com/stack-set-2-infix-to-postfix/

/*
 * My php code:

function level($op) {
	switch ($op) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
}

function infix2postfix($expr) {
	$len = count($expr);
	$stack = array();
	$postfix = array();
	for($i = 0; $i < $len; $i++) {
		if(is_numeric($expr[$i])) {
			$postfix[] = $expr[$i];
		}
		else {
			if($expr[$i] == '(') {
				array_push($stack, $expr[$i]);
			}
			if($expr[$i] == '+' || $expr[$i] == '-' || $expr[$i] == '*' || $expr[$i] == '/') {
				if(!empty($stack)){
					$op = array_pop($stack);
					if($op != '(' && (level($op) >= level($expr[$i]))) {
						array_push($postfix,$op);
					}
					else {
						array_push($stack, $op);
					}
				}
				array_push($stack, $expr[$i]);
			}
			if($expr[$i] == ')') {
				while(($op = array_pop($stack)) != '(') {
					array_push($postfix,$op);
				}
			}
		}
	}
	// 8-(2-6)*4
	while(($last_op = array_pop($stack)) != NULL){
		array_push($postfix, $last_op);
	}

	return $postfix;
}

 */
