#!/bin/bash

result_file="test_result"

> "$result_file"

for test_dir in tests/*; do
    if [ -d "$test_dir" ]; then
        input_c=$(find "$test_dir" -name "*.c")
        output_out=$(find "$test_dir" -name "*.out")
        input_in=$(find "$test_dir" -name "*.in")

        if [ -z "$input_c" ] || [ -z "$output_out" ]; then
            echo "Skipping $test_dir: Missing .c or .out file." >> "$result_file"
            continue
        fi

        asm_file="${test_dir}/output.s"
        exe_file="${test_dir}/output.exe"

        ./sysc "$asm_file" "$input_c"
        if [ $? -ne 0 ]; then
            echo "Error: sysc failed for $input_c" >> "$result_file"
            continue
        fi

        g++ -o "$exe_file" "$asm_file"
        if [ $? -ne 0 ]; then
            echo "Error: g++ failed to compile $asm_file" >> "$result_file"
            continue
        fi

        if [ -n "$input_in" ]; then
            cat "$input_in" | "$exe_file" > "${test_dir}/actual_output.tmp"
        else
            "$exe_file" > "${test_dir}/actual_output.tmp"
        fi

        if diff -q -Z "${test_dir}/actual_output.tmp" "$output_out" > /dev/null; then
            echo "$test_dir: Success" >> "$result_file"
        else
            echo "$test_dir: Failure" >> "$result_file"
            echo "Expected:" >> "$result_file"
            cat "$output_out" >> "$result_file"
            echo "Got:" >> "$result_file"
            cat "${test_dir}/actual_output.tmp" >> "$result_file"
        fi

        rm -f "$asm_file" "$exe_file" "${test_dir}/actual_output.tmp"
    fi
done
