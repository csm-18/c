

const VERSION:&str = "0.1.0";
fn main() {
    //cli args
    let args: Vec<String>= std::env::args().collect();

    if args.len() == 1 {
        println!("cpp {VERSION}");
        println!(" A preprocessor for c language, part of csm-18/c project.");
        println!("for usage:\n cpp --help");
    }else if args.len() == 2 && args[1] == "--help" {
        println!("cpp commands:");
        println!(" 1.cpp <no args> -> prints cpp version and about message.");
        println!(" 2.cpp  --help   -> prints this commands list.");
    }
}
