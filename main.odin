package main

import "core:fmt"
import "core:os"
import "core:mem"

VERSION :: "0.0.1"
main :: proc(){
    args := os.args

    if len(args) == 1{
        fmt.println("c",VERSION)
    }else if len(args) == 2{
        if args[1] == "version" || args[1] == "-v" || args[1] == "--version" || args[1] == "-version"{
            fmt.println("c",VERSION)
        } else if args[1] == "init" {
            fmt.println("c: initializing project in current directory...")

            //check if src/ folder exists
            if os.is_dir_path("src") {
                fmt.println("Error: src/ folder already exists")
                os.exit(1)
            }

            //check if build/ folder exists
            if os.is_dir_path("build") {
                fmt.println("Error: build/ folder already exists")
                os.exit(1)
            }


            //create src/ folder
            src_err := os.make_directory("src")
            if src_err != nil {
                fmt.println("Error: could not create src/ folder")
                os.exit(1)
            }else{
                fmt.println("  created src/")
            }


            //create build/ folder
            build_err := os.make_directory("build")
            if build_err != nil {
                fmt.println("Error: could not create build/ folder")
                os.exit(1)
            }else{
                fmt.println("  created build/")
            }

            //create main.c file
            main_dot_c_success := os.write_entire_file("src/main.c", hello_world_c_code_bytes)
            if !main_dot_c_success {
                fmt.println("Error: could not create src/main.c")
                os.exit(1)
            }else{
                fmt.println("  created src/main.c")
            }


        }
            
    }
}



hello_world_c_code := "#include <stdio.h>\n\nint main(int argc, char *argv[]) {\n    printf(\"Hello, World!\\n\");\n    return 0;\n}"
hello_world_c_code_bytes := transmute([]u8)(hello_world_c_code)