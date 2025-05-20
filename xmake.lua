add_rules("mode.debug", "mode.release")

set_project("pta")
set_version("0.0.0")
set_languages("gnuxx98")

target("pta", function()
	set_kind("binary")
	add_files("src/main.cpp")

	add_cxxflags("-O2", "-Wall", "-Wextra")

	add_defines("ONLINE_JUDGE")

	if is_mode("debug") then
		add_defines("DEBUG")
	end

	add_links("m")
end)
