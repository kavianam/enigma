# Enigma Machine Simulator

![image](https://historyonthisday.com/wp-content/uploads/2018/05/enigma-machine.jpg)

The Enigma machine is an encryption device developed and used in the early- to mid-20th century to protect commercial, diplomatic and military communication. It was employed extensively by Nazi Germany during World War II, in all branches of the German military.
In typical use, one person enters text on the Enigma's keyboard and another person writes down which of 26 lights above the keyboard lights up at each key press. If plain text is entered, the lit-up letters are the encoded ciphertext. Entering ciphertext transforms it back into readable plaintext. The rotor mechanism changes the electrical connections between the keys and the lights with each keypress. For more information check out it's [Wikipedia page](https://en.wikipedia.org/wiki/Enigma_machine)

Enigma has three rotors that scramble the 26 letters of the alphabet and a Reflector at the end which map each character to its opposite character in alphabetic. Enigma has different rotors that in the given coodbook it is specified. 
`coodbook_maker.c` generates the `coodbook.txt` that explain which rotors to use. `enigma.c` then read that file and encrypt and decrypt texts according to it.

# How to run

```bash
make
echo attack | ./enigma
```
