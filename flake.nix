{
  description = "Default flake-parts based setup";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-26.05";
    mini_cc = {
      url = "github:danielbarter/mini_compile_commands";
      flake = false;
    };
    flake-parts.url = "github:hercules-ci/flake-parts";
    import-tree.url = "github:vic/import-tree";
    systems.url = "github:nix-systems/default";
    treefmt-nix = {
      url = "github:numtide/treefmt-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = inputs:
    inputs.flake-parts.lib.mkFlake {inherit inputs;} {
      imports = [inputs.treefmt-nix.flakeModule];
      systems = import inputs.systems;
      perSystem = {
        pkgs,
        self',
        ...
      }: let
        mcc-env = (pkgs.callPackage inputs.mini_cc {}).wrap pkgs.stdenv;
      in {
        packages = {
          VTM = pkgs.qt6.callPackage ./default.nix {};
          default = self'.packages.VTM;
        };

        devShells.default = ( pkgs.mkShell.override {stdenv = mcc-env;} ) {
          inputsFrom = [ self'.packages.default ];
        };
        treefmt = import ./treefmt.nix;
      };
    };
}
