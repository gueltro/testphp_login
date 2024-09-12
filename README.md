# Overview
This console app attempts to login at http://testphp.vulnweb.com/login.php and prints the resulting HTML page.

## Building

```bash
git clone https://github.com/gueltro/testphp_login
cd testphp_login
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

This app allows logging into http://testphp.vulnweb.com/login.php by providing a combination of USERNAME and PASSWORD, or by exclusively providing USERNAME.
If the PASSWORD is not provided, the app will attempt to bypass the password validation.

```
testphp_login_app USERNAME PASSWORD
testphp_login_app USERNAME
```

## Executing

Form inside the `build/` directory run:

### Linux

```bash
./testphp_login_app USERNAME PASSWORD
```

or 

```bash
./testphp_login_app USERNAME
```

### Windows

```bash
.\Debug\testphp_login_app.exe USERNAME PASSWORD
```

or

```bash
.\Debug\testphp_login_app.exe USERNAME
```

## Requirements
- C++17 compatible compiler such as Clang or GCC (see requirements from https://github.com/libcpr/cpr for details on the compatibility of the compilers).
- cmake >= 3.20
- Linux or Windows (tested on Debian 12 and Windows 11).

## Credits
This app uses cpr and was built using https://github.com/libcpr/example-cmake-fetch-content.git as a starting point.
