import pkgs = {*/ -*-tests/ -upstream/}
import tests = {*-tests/}

./: $pkgs
./: $tests: install = false
