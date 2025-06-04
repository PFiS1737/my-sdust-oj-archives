function showws -d "Show file content with trailing whitespace highlighted"
    set filename $argv[1]

    if not test -f "$filename"
        echo "No such file: $filename" >&2
        return 1
    end

    set -l use_color 0
    if test -t 1
        set use_color 1
    end

    while read -l line
        if string match -qr '\s+$' -- "$line"
            echo -n -- (string replace -r '\s+$' '' -- "$line")

            if test $use_color -eq 1
                set_color brblack
            end

            echo -- (string replace -ar "." "-" -- (string match -r '\s+$' -- "$line"))

            if test $use_color -eq 1
                set_color normal
            end
        else
            echo "$line"
        end
    end <"$filename"
end
