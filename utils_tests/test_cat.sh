#! /bin/bash

MY_BIN="../src/cat/gh-test-cat"
PASS_COUNT=0
FAIL_COUNT=0

run_test() {

	cat input > cat_out
	$MY_BIN input > my_out

	cmp cat_out my_out

	if [ $? -eq 0 ]; then
		(( PASS_COUNT += 1 ))
	else
		echo "$DESCRIPTION test failed"
		(( FAIL_COUNT += 1 ))
	fi

	rm my_out cat_out

	return 
}

DESCRIPTION="Normal"
cat > input <<END
LINE 1
LINE 2
END
run_test; rm input

DESCRIPTION="Blank line at end"
cat > input <<END
LINE 1
LINE 2

END
run_test; rm input

DESCRIPTION="Blank line in middle"
cat > input <<END
LINE 1

LINE 2
END
run_test; rm input

DESCRIPTION="Empty"
cat > input <<END
END
run_test; rm input

DESCRIPTION="One blank line"
cat > input <<END

END
run_test; rm input

DESCRIPTION="Two blank lines"
cat > input <<END


END
run_test; rm input

echo "Pass count: $PASS_COUNT Fail count: $FAIL_COUNT"
