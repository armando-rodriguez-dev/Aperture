use std::env;
use std::fs; 


const VALID_COMMANDS: [&str; 6] = [
    "init",
    "status",
    "add",
    "commit",
    "log",
    "help"
];

///Checks whether the command is one of the valid commads.
/// 
/// ### Arguments
/// 
/// * 'valid_command_array' - The list of valid commands.
/// * 'command' - The command provided by the user.
/// 
/// ### Returns
/// 
/// 'true' if the command is valid, otherwise 'false'.
fn is_valid_command(valid_command_array: [&str; 6], 
                    command: &str
    ) -> bool {

    for valid_commands in valid_command_array {
        if valid_commands == command {
            return true;
        }
    }

    return false;
}

fn main() -> std::io::Result<()> {    
    //Read the command line argument
    let args: Vec<String> = env::args().collect();

    //Store the current working directory
    let path = env::current_dir()?;

    //Store all current directory items
    let items_in_current_directory = fs::read_dir("./").unwrap();

    
    //Check if the current args was valid
    //The command for Aperture will be in the arr[1] index
    if !is_valid_command(VALID_COMMANDS, &args[1]) {
        println!("Invalid Command");
    }




    Ok(())
}
