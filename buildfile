import pkgs = {*/ -*-tests/ -upstream*/}
import tests = {*-tests/ -upstream*/}

./: $pkgs
./: $tests: install = false
