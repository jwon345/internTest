# Design descisions.

My assumptions are that no new commands will be added during runtime.

## Command
### unique identifier 
			I've decided to use a unsigned 8 bit integer to reduce memory usage. 
			to make it more readable, an enum is used->CommandName, to make indexing more readable

### Command Type.
			the Command type follows the same structure of the Unique identifier.
			instead of using strings taking up 8bits per character. a single byte can be used to represent
			a command type with an enum -> commandType to make it readable
		
### Parameters.
			This one is too vague to optimise for. therefore i've decided that 2 paramters would be enough
			to cover all, if not most of the commands parameter needs.
			since i believe accuracy would be an important aspect, a float was used to represent non integer			numbers. if more accuracy were needed doubles could be substituted.

			
		The usage of Enums
			these were used to reduce the need of having strings/equivalent to use for indentification, which 			takes a big chuck of memory

## List of Commands
### An array of the command struct.	
			having a Fixed number elements does reduce the ease of use in terms of adding in new commands.
			but does lower the memory usage of the program, as the array size can be carefully allocated 
			with each command before runtime. it provides greater memory usage.
	
			although if commands were needed to be allocated during runtime I believe a linked list would be 			a solution that doesn't require external libraries.

## How to use 
	
	To add a new command. a commandName should be added in order to the commandName enum.
	if the list is full, the defined ListSize should be incremented 
	then in the constructor, call the function addCommand. parameters, commandName, CommandType -> this is used 	to describe the function of the command and what parameters will be used.
	Paramter A, Paramters B if needed. 

	referencing the command is done by calling the class fucntion commandstore.run(commandName) ///index
		where pseudo command execution is sorted and committed.

	there are also getter fucntions to view the contents of each command
