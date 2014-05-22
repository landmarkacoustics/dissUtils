#!perl -w

use strict;

while(<@ARGV>){

    my $U = uc $_;

    open(my $fh, ">", "$_.hpp")
	or die "cannot open > $_.hpp: $!";

    print($fh "#ifndef BNT_DIFFERENCE_", $U, "_H\n",
    "#define BNT_DIFFERENCE_", $U, "_H 1\n",
    "#include \"base.hpp\"\n",
    "namespace BNT {\n",
    "namespace Difference {\n",
    "template<typename T>\n",
    "struct $_ : public Base<T> {\n",
    "typedef typename Base<T>::va_t va_t;\n",
    "T Diff(const va_t& a, const va_t& b) const {\n",
    "//fill in\n",
    "}\n",
    "Base<T>* Clone() const { return new $_; }\n",
    "};\n",
    "}\n",
    "}\n",
    "#endif\n");

    close $fh;
}
