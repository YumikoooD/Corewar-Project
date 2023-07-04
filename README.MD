# Corewar

Corewar is a project inspired by the game of the same name, where champions battle in a virtual arena. Each champion is written in Corewar's specific assembly language and is executed by a virtual machine called the "corewar".

## Features

- Compilation of champions into bytecode executable by the asm binary
- Process and instruction management
- Detection of the winning champion
- Bonus added feature:
  - Generation of an image of the winning champion using Midjourney or WALL.E

## Examples

Here's how to compile and run a champion in the core:

```bash
$ ./asm champion.s      # Compile the champion into bytecode
$ ./corewar champion.cor     # Run the core with the champion

To generate an image of the winning champion using Midjourney, execute the following command after completing a game:

python "MidJourney.py"
--> Connect you to discord. 
--> Describe the Champion to the discord bot.
--> The CHampion description will be download in the output folder !

To generate an image of the winning champion using DALL.E, execute the following command after completing a game:

python "ia.c" "champion.txt"
--> That it ! Your Champion description could be found at the root of the repository ! 


NB: For use this function don't forget to replace discord token for MJ and the openai token for DALL.E ! (obvviously I will not push my token, im not rich).
