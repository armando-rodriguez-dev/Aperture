use std::env;

const VALID_COMMANDS: [&str; 5] = [
    "init",
    "status",
    "add",
    "commit",
    "log"
];

fn main() -> std::io::Result<()> {    
    //Read the command line argument
    let args: Vec<String> = env::args().collect();

    let path = env::current_dir()?;
    println!("The current directory is {}", path.display());
    Ok(())
}
