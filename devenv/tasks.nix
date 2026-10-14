{
  tasks = {
    "vtm:build" = {
      exec = ''
        mkdir -p build
        cd build
        cmake -S .. -DCMAKE_BUILD_TYPE=Debug
        make
      '';
    };

    "vtm:gen_cc" = {
      exec = ''
        mkdir -p build
        cd build
        cmake -S .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
        cp compile_commands.json ../
      '';
    };

    "vtm:release" = {
      exec = ''
        mkdir -p build
        cd build
        cmake -S ..
        make
      '';
    };
  };
}
