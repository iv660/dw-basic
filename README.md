# DW BASIC
DW BASIC is an experimental implementation of the BASIC programming language.

## Usage
Run the compiled executable file from console.

### Command Mode

The command mode is a command interface to manage your BASIC programs. In this mode, enter the commands after you get the `Ok` prompt in your console.

```
DW BASIC 2024 V0.0.1
Ok
```

### Available Commands
In command mode, you can enter the following commands.

> NOTE. All commands are case-insensitive.

#### RUN
Executes the program currently available in BASIC interpreter memory.

#### LIST
Prints the listing of program currently available in BASIC interpreter memory.

#### NEW
Deletes the entire program from BASIC interpreter memory.

#### EXIT
Ends the BASIC interpreter session.

### Editing a Program
In command mode, enter the program line by line starting with a line number. To finish a line and store it in memory, hit `Enter`.

### BASIC Syntax

BASIC program consists of sequence of lines of code. Each line has the following structure:

```basic
<LINE_NUMBER> <INSTRUCTION> [<ARGUMENT>[, <ARGUMENTS>]]
```

`LINE_NUMBER` is an integer representing the line position, and could also be used as a label for conditional and unconditional jumps.

`INSTRUCTION` is a code name of operation to be executed when the line is processed by BASIC interpreter.

Optional `ARGUMENTS` represent parameters for the instruction.

Spaces between different parts of the line are optional.

### Available Instructions
#### REM
`REM` instruction (*remark*) is used to write comments for the code. Any text after the `REM` instruction up to the end of the line is ignored.

```basic
10 REM Comment text
```

#### PRINT
Outputs the expression value to console.

##### Basic syntax:

```basic
<LINE_NUMBER> PRINT <EXPRESSION>
```

##### Examples:

```basic
10 PRINT "Hello, World!"
```

```basic
10 PRINT 42
```

### Expressions
#### String Literals
String literal is a sequence of characters enclosed in double quotes (`"`).

```basic
"My name is John"
```

To include the double quote character in string literal, it must be escaped with another double quote.

```basic
"The answer is ""Yes"""
```

#### Integer Literals
Integer literal is a plain decimal number.

```basic
61
```

When used in string context, integer literals are implicitly converted to their string representation.

```basic
10 PRINT 61
20 REM The same as 10 PRINT "61"
```
