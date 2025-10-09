package main

import "core:fmt"
import "core:os"

VERSION :: "0.0.1"
main :: proc(){
    args := os.args

    if len(args) == 1{
        fmt.println("c",VERSION)
    }else if len(args) == 2{
        if args[1] == "version" || args[1] == "-v" || args[1] == "--version" || args[1] == "-version"{
            fmt.println("c",VERSION)
        }
            
    }
}