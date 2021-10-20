
# Expression Matching
Stack data structure for solving a matching expression problem given the inputs "{", "[" and "(".

## Installation:

`Note: python 3 and cmake is required`

1. Clone the repo
```git
git clone https://github.com/berazo29/expressionMatching.git
```
2. Go inside the project
```sh
cd expressionMatching
```
3. Build the project with the python script
```py
python run.py
```

## Usage

Inside the folder `build` there is the executable `main`. 
There is a pre-defined example in `main`

*Example:*
```
./main 
```
*Output:*
```
Expression: () Valid: 1
Expression: ( Valid: 0
Expression: (){}[] Valid: 1
Expression: ()) Valid: 0
Expression: [()) Valid: 0
Expression: {[()][()]} Valid: 1
Expression: ((()(()))) Valid: 1
```
`Note: This function does not check for expression precedence.
   Therefore the expresion ([]) and [()] are both valid`
<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>

