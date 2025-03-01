%define _unpackaged_files_terminate_build 1

Name:    hangman
Version: 1.1
Release: alt1
Summary: Most simple RPM package
License: GPL
Group:   Games/Arcade
Source:  %name-%version.tar
BuildRequires: gcc-c++

%description
Hangman game

%prep
%setup -n %name

%build
%make_build hangman

%install
mkdir -p %{buildroot}%_bindir
install -m 755 hangman %{buildroot}%_bindir

%files
%_bindir/%name

%changelog
* Mon Apr 01 2024 Some One <someone@altlinux.org> 1.0-alt1
- Init Build
