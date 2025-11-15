# VerySillyMUD
A refactoring exercise based on SillyMUD, a derivative of DikuMUD.

Modified to run on an Espressif devit.

# Building

```
$ cd src
$ make
```

# Running the game

Within the src folder after building:
```
$ ./sillymud -d ../lib
```

The major note is that the first player to log in will become an
"Implementor" level god; after the first log in, that player will need
to have an entry in the [`security`](lib/security/) directory. See the [`README`](lib/security/README) file in
that directory for more details.


Further documentation for running the game is found in [`running.doc`](doc/running.doc).
