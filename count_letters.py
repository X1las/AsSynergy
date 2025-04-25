import re

def count_letters_in_latex(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.read()
            
            # Cut off everything after appendix
            appendix_patterns = [r'\\appendix', r'\\begin\{appendix\}']
            for pattern in appendix_patterns:
                match = re.search(pattern, content, re.IGNORECASE)
                if match:
                    content = content[:match.start()]
            
            # Remove LaTeX commands
            content = re.sub(r'\\[a-zA-Z]+(\[.*?\]|\{.*?\})*', '', content)
            
            # Remove environments and their contents
            content = re.sub(r'\\begin\{.*?\}.*?\\end\{.*?\}', '', content, flags=re.DOTALL)
            
            # Remove citations
            content = re.sub(r'\\parencite\{.*?\}', '', content)
            
            # Remove special characters and numbers
            content = re.sub(r'[^a-zA-Z]', '', content)
            
            letter_count = len(content)
            return letter_count
            
    except FileNotFoundError:
        return "Error: File not found"
    except Exception as e:
        return f"Error: {str(e)}"

# Count letters
result = count_letters_in_latex(r'report/main.tex')
print(f"Number of letters (excluding LaTeX commands and technical content): {result}")