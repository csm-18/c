use std::process::exit;



const VERSION:&str = "0.1.0";
fn main() {
    //cli args
    let args: Vec<String>= std::env::args().collect();

    if args.len() == 1 {
        println!("cpp {VERSION}");
        println!(" A preprocessor for c language, part of csm-18/c project.");
        println!("for usage:\n cpp --help");
    }else if args.len() == 2 && args[1] == "--help" {
        println!("cpp {VERSION}");
        println!("Commands:");
        println!(" cpp <no args>        -> prints cpp version and about message.");
        println!(" cpp --help           -> prints this commands list.");
        println!(" cpp <c source files> -> preprocess c source files.");
        println!();
        println!("Subcommands:");
        println!(" -I<include path>     -> include path for c header files.");
    }else {
        //c source files
        let mut c_src_files: Vec<String> = vec![];
        
        //include paths for c header files
        let mut include_paths: Vec<String> = vec![];
        //first path is to the std lib (musl)
        include_paths.push("../../musl-build/install/include/".to_string());

        //c header files
        // let mut c_header_files: Vec<String> = vec![];
        
        for arg in args[1..].iter() {
            if arg.len() >= 3 && &arg[arg.len()-2..] == ".c" {
                c_src_files.push(arg.to_string());
                
            }else if arg.len() >= 3 && &arg[0..2] == "-I" {
                include_paths.push(arg[2..].to_string());
            }else {
                println!("cpp error: invalid arguments!");
                exit(1);
            }
        }
    }
}
