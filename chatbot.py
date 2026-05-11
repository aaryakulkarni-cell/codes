from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB

# Training data (more variety)
sentences = [
    # Greetings
    "hello", "hi", "good morning", "hey", "good evening",

    # Admission
    "how to take admission", "admission process", "apply for college",
    "how to join college", "admission details",

    # Courses
    "what courses are offered", "available courses", "engineering branches",
    "computer engineering course", "which courses available",

    # Fees
    "what is the fees", "fees structure", "college fees",
    "how much fees", "tuition fees",

    # Exams
    "exam schedule", "when are exams", "exam dates",
    "semester exams", "exam timetable",

    # Timetable
    "class timetable", "lecture schedule", "daily schedule",
    "when are classes", "class timing",

    # Faculty
    "who are teachers", "faculty details", "professors",
    "staff information", "teaching staff",

    # Placement
    "placement details", "companies visiting", "job opportunities",
    "campus placement", "placement percentage"
]

labels = [
    # Greetings
    "greeting","greeting","greeting","greeting","greeting",

    # Admission
    "admission","admission","admission","admission","admission",

    # Courses
    "courses","courses","courses","courses","courses",

    # Fees
    "fees","fees","fees","fees","fees",

    # Exams
    "exam","exam","exam","exam","exam",

    # Timetable
    "timetable","timetable","timetable","timetable","timetable",

    # Faculty
    "faculty","faculty","faculty","faculty","faculty",

    # Placement
    "placement","placement","placement","placement","placement"
]

# Convert text to numbers
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(sentences)

# Train model
model = MultinomialNB()
model.fit(X, labels)

print("🎓 College Chatbot (type 'exit' to stop)\n")

# Chat loop
while True:
    user_input = input("You: ").lower()

    if user_input == "exit":
        print("Bot: Thank you! Have a nice day.")
        break

    # Transform input
    input_vec = vectorizer.transform([user_input])

    # Predict intent
    prediction = model.predict(input_vec)[0]

    # Responses
    if prediction == "greeting":
        print("Bot: Hello! Welcome to our college. How can I assist you?")
    
    elif prediction == "admission":
        print("Bot: Admission is based on entrance exams and merit. Visit the college website for details.")
    
    elif prediction == "courses":
        print("Bot: We offer Computer, IT, Mechanical, Civil, and Electronics Engineering.")
    
    elif prediction == "fees":
        print("Bot: The average annual fees is around ₹80,000. It may vary by course.")
    
    elif prediction == "exam":
        print("Bot: Exams are conducted at the end of each semester. Timetable will be announced soon.")
    
    elif prediction == "timetable":
        print("Bot: Classes are usually from 10 AM to 5 PM. Check your department notice for details.")
    
    elif prediction == "faculty":
        print("Bot: Our faculty includes experienced professors and industry experts.")
    
    elif prediction == "placement":
        print("Bot: Top companies visit for placements. Average package is around ₹4-6 LPA.")
    
    else:
        print("Bot: Sorry, I didn't understand. Please ask something else.")