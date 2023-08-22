with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "buildmapasm";
  src = ./.;
  buildPhase = "make";
  installFlags = "PREFIX=$(out)";
  buildInputs = [ pkg-config libxml2 ];
}
