{
  git-hooks.hooks = {
    alejandra = {
      enable = true;
      files = "\\.(nix)$";
    };
    clang-format = {
      enable = true;
      files = "\\.(h|hpp|cpp|c)$";
    };
  };
}
